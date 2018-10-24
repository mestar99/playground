
import * as sinon from 'sinon';
import { expect } from 'chai';

function returnPromise() {
    return new Promise<string>((resolve,reject) => setTimeout(resolve,1000))
        .then( (value) => {
            console.log(value);
            return new Promise<string>((resolve,reject) => resolve("hello"));
        });
}

describe('basic', function() {
    
    it('should return -1 when the value is not present', function() {
        
        expect([1,2,3].indexOf(4)).to.equal(-1);
    });

    it('should resolve', function() {
        
        let task = returnPromise();

        return task
            .then( (value) => {
                console.log(value);

                return new Promise<string>((resolve, reject) => resolve(value+"world"));
            })
            .then( (value) => {
                
                console.log(value);
            });
    });
});
