const express = require("express");
const Handler = require("../handler/handler");
const router = express.Router();

// home route (entry point)
router.get("/", (req, res, next) => {
    res.send("hello world");
});

// CRUD
router.post("/student", Handler.createStudent);

router.post("/faculty", Handler.createFaculty);

router.get("/student/:id", Handler.readStudent);

router.get("/faculty/:id", Handler.readFaculty);

router.get("/student", Handler.readAllStudent);

router.get("/faculty", Handler.readAllFaculty);

router.put("/student/:id", Handler.updateStudent);

router.put("/faculty/:id", Handler.updateFaculty);

router.delete("/student/:id", Handler.deleteStudent);

router.delete("/faculty/:id", Handler.deleteFaculty);

router.delete("/student", Handler.deleteAllStudent);

router.delete("/faculty", Handler.deleteAllFaculty);

module.exports = router;
