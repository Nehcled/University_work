const mysql = require("mysql");

let connection = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",
    database: "db_system_schema",
})

module.exports = connection;