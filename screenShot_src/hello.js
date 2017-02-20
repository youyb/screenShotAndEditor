var qt = require('./build/Release/qt.node');

//var dir = "C:/work/ws/out/";
var dir = "/Users/yyb/out/";
var app = new qt.MyQApp;

console.log('image path: ' + app.screenCapture(dir));