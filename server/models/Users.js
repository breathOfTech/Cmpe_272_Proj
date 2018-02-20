const mongoose = require('mongoose');
const { Schema } = mongoose; //const Schema = mongoose.Schema;

const userSchema = new Schema({
  googleId: String
});

//collection of users
mongoose.model('users', userSchema);
