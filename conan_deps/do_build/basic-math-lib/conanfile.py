from conans import ConanFile, CMake, tools

class BasicMathLibConan(ConanFile):
    name = "basic-math-lib"
    version = "2.2"
    description = "Basic Math Library"

    settings = "os", "compiler", "build_type", "arch"
    url = "None"
    license = "None"
    exports_sources = "src/*", "CMakeModules/*"

    def build(self):

        cmake = CMake(self)

        self.run('cmake %s/src '
                 '-DCMAKE_CXX_COMPILER=/opt/gcc-4.9.2/bin/g++ '
                 '-DCMAKE_C_COMPILER=/opt/gcc-4.9.2/bin/gcc '
                 '-DCMAKE_INSTALL_PREFIX=%s '
                 '-DCMAKE_BUILD_TYPE=%s'
                 % (self.source_folder, cmake.definitions["CMAKE_INSTALL_PREFIX"], cmake.definitions["CMAKE_BUILD_TYPE"]) )

        print(cmake.command_line)
        print(cmake.build_config)

        self.run("cmake --build . -- -j %s" % tools.cpu_count())
        self.run("cmake --build . --target install")

    def package(self):

        self.copy("*", dst="", src="package")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)

    def deploy(self):
        self.copy("*", dst="/opt/conan_blade", src="")

    
