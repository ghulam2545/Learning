const express = require("express");
const routes = require("./routes/routes");
const { APP_PORT } = require("./config/config");
const connectDatabase = require("./database/dbs");

const app = express();

app.use(express.json());

// initializing route middleware
app.use(routes);

// connection to the database
connectDatabase();

app.listen(APP_PORT, () => {
    console.log(`listening on port ${APP_PORT}.`);
});
