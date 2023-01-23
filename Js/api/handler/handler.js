const { Student, Faculty } = require("../model/model");

const Handler = {
    async createStudent(req, res, next) {
        try {
            if (!req.body) {
                res.send("req body could not be empty");
                return;
            }

            const { username, password } = req.body;

            const student = new Student({ username, password });

            const result = await student.save();

            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async createFaculty(req, res, next) {
        try {
            if (!req.body) {
                res.send("req body could not be empty");
                return;
            }

            const { username, password } = req.body;

            const faculty = new Faculty({ username, password });

            const result = await faculty.save();

            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async readStudent(req, res, next) {
        try {
            const id = req.params.id;
            const result = await Student.findById(id);
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async readFaculty(req, res, next) {
        try {
            const id = req.params.id;
            const result = await Faculty.findById(id);
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async readAllStudent(req, res, next) {
        try {
            const result = await Student.find({}, { __v: 0 });
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async readAllFaculty(req, res, next) {
        try {
            const result = await Faculty.find({}, { __v: 0 });
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async updateStudent(req, res, next) {
        try {
            const { username, password } = req.body;

            const id = req.params.id;
            const student = await Student.findByIdAndUpdate(
                { _id: id },
                { username, password }
            );

            const result = await student.save();

            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async updateFaculty(req, res, next) {
        try {
            const { username, password } = req.body;

            const id = req.params.id;
            const student = await Faculty.findByIdAndUpdate(
                { _id: id },
                { username, password }
            );

            const result = await Faculty.save();

            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async deleteStudent(req, res, next) {
        try {
            const id = req.params.id;
            const result = await Student.deleteOne({ _id: id });
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },
    async deleteFaculty(req, res, next) {
        try {
            const id = req.params.id;
            const result = await Faculty.deleteOne({ _id: id });
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async deleteAllStudent(req, res, next) {
        try {
            const result = await Student.deleteMany({});
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },

    async deleteAllFaculty(req, res, next) {
        try {
            const result = await Faculty.deleteMany({});
            res.send(result);
        } catch (err) {
            res.send(err);
        }
    },
};

module.exports = Handler;
