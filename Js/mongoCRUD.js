/**
 * this is just single JS file.
 * do all other init/install required packages
 * any other lol thing to see in action.
 */

const { MongoClient } = require("mongodb");

async function main() {
    const url = "mongodb://127.0.0.1:27017";
    const client = new MongoClient(url);

    try {
        await client.connect();
        const my_dbs = client.db("space");

        // call here
    } catch (err) {
        throw err;
    } finally {
        client.close();
    }
}

main().catch(console.error);

async function ListDateBase(client) {
    const db_list = await client.db().admin().listDatabases();
    console.log(`list of databases : <count : ${Object.keys(db_list).length}>`);

    console.log(db_list);
}

async function CreateCollection(db_name, coll) {
    try {
        const result = await db_name.createCollection(coll);
    } catch (err) {
        throw err;
    } finally {
        console.log(`new collection named [ ${coll} ] in created.`);
    }
}

async function DropCollection(db_name, coll) {
    try {
        // returns true on success
        const result = await db_name.collection(coll).drop();
    } catch (err) {
        throw err;
    } finally {
        console.log(`collection named [ ${coll} ] is droped.`);
    }
}

async function InsertOne(db_name, coll, doc) {
    try {
        const result = await db_name.collection(coll).insertOne(doc);
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("new document inserted successfully.");
    }
}

async function InsertMany(db_name, coll, doc) {
    try {
        const result = await db_name.collection(coll).insertMany(doc);
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("new documents inserted successfully.");
    }
}

async function ReadOne(db_name, coll, by_doc) {
    try {
        const result = await db_name.collection(coll).findOne(by_doc);
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("founded collection are above.");
    }
}

async function ReadMany(db_name, coll, by_doc) {
    try {
        const all = await db_name.collection(coll).find(by_doc);
        const result = await all.toArray();
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("founded collections are above.");
    }
}

async function DeleteOne(db_name, coll, doc) {
    try {
        const result = await db_name.collection(coll).deleteOne(doc);
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("one deletion successful.");
    }
}

async function DeleteMany(db_name, coll, doc) {
    try {
        const result = await db_name.collection(coll).deleteMany(doc);
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("many deletion successful.");
    }
}

async function UpdateOne(db_name, coll, old_doc, new_doc) {
    try {
        const result = await db_name
            .collection(coll)
            .updateOne(old_doc, { $set: new_doc });
        console.log(result);
    } catch (err) {
        throw err;
    } finally {
        console.log("one updation successful.");
    }
}

async function UpdateMany(db_name, coll, old_doc, new_doc) {
    try {
        const result = await db_name
            .collection(coll)
            .updateMany(old_doc, { $set: new_doc });
    } catch (err) {
        throw err;
    } finally {
        console.log("many updation successful.");
    }
}
