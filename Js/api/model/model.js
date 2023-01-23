const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const studentSchema = new Schema({
    username: {
        type: String,
        required: true,
    },
    password: {
        type: String,
        required: true,
    },
});

const facultySchema = new Schema({
    username: {
        type: String,
        required: true,
    },
    password: {
        type: String,
        required: true,
    },
});

const Student = mongoose.model("Student", studentSchema);
const Faculty = mongoose.model("Faculty", facultySchema);

module.exports = { Student, Faculty };
