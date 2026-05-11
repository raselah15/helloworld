var express = require("express");

var app = express();

var HTTP_PORT = process.env.PORT || 8080;

// Home Route
app.get("/", (req, res) => {
    res.send(`
        <h1>Hello World!</h1>
        <br/>
        <a href="/about">Go to /about route</a>
    `);
});

// About Route
app.get("/about", (req, res) => {
    res.json({
        course: "WEB322",
        student: "RASEL AHMMED",
        task: "In-class Assignment 1"
    });
});

// Start Server
app.listen(HTTP_PORT, () => {
    console.log(`Server listening on: http://localhost:${HTTP_PORT}`);
});