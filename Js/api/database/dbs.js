const mongoose = require("mongoose");
const { DB_URI } = require("../config/config");

mongoose.set("strictQuery", false);

async function connectDatabase() {
    try {
        await mongoose.connect(DB_URI);
        console.log("database connection success.");
    } catch (err) {
        console.log("database connection fail.");
        console.error(err);
    }
}

module.exports = connectDatabase;
