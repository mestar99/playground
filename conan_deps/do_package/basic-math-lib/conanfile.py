from conans import ConanFile, tools


class BasicmathlibConan(ConanFile):
    name = "basic-math-lib"
    version = "2.2"
    settings = "os", "compiler", "build_type", "arch"
    description = "<Description of Basicmathlib here>"
    url = "None"
    license = "None"
    author = "None"
    topics = None

    def package(self):
        self.copy("*")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)

    def deploy(self):

        print("deploy!")

        self.copy("*", dst="bin", src="bin")
        self.copy("*", dst="include", src="include")
        self.copy("*", dst="lib", src="lib")
        self.copy("*", dst="CMakeModules", src="CMakeModules")
