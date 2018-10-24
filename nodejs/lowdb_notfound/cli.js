
"use strict";

const low = require('lowdb');
const FileAsync = require('lowdb/adapters/FileAsync');

const adapter = new FileAsync('db.json');

const localdb = low(adapter)
    .then((db) => {
        console.log('#1');
        //console.log(db);

        return db.defaults({ workerErrors: [], workers: [] }).write()
            .then(() => {
                return db;
            });
    })
    .then((db) => {
        console.log('#2');
        //console.log(db);
        
        return db.get('workers').push({ name: 'worker1', logExpired: false }).write()
            .then((val) => {
                console.log('registered');
                
                return db;
            }, (err) => {
                console.log('not registered');
            });
        
    })
    .then((db) => {
        console.log('#3');
        console.log(db);
        
        /*
        return new Promise((resolve,reject) => {
            let result = db.get('workers').find({ name: 'worker2' }).value();

            if(result) {
                //resolve(result.assign({ logExpired: true }).write());
                //console.log(`result: ${result}`);
                //console.log(result.assign({ logExpired: true }));
                //result.assign({ logExpired: true});
                console.log(result);
                
                resolve(db.get('workers').find({ name: 'worker2' }).assign({ logExpired: true }).write());
            }
            else {
                resolve();
            }
        })
            .then((val) => {
                console.log(val);
            });
        */
        
        return db.get('workers').find({ name: 'worker2' }).assign({ logExpired: true }).write();

        /*
            .then((val) => {
                console.log(`value: ${value}`);

                return db;
            })
            .catch((err) => {
                console.log(err);
            });
*/
/*
            .assign({ logExpired: true }).write()
            .then(() => {
                console.log('expired');

                return db;
            }, (err) => {
                console.log('worker not found');
            });
*/
    })
    .then((db) => {
        console.log('#4');
        console.log(db);

        console.log('finished');
    });



