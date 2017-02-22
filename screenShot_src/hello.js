var sc = require('./build/Release/screencapture.node');

//var dir = "C:/work/ws/out/";
var dir = "/Users/yyb/out/";
var app = new sc.Main;

// console.log('image path: ' + app.screenCapture(dir));

app.screenCapture(dir, function(str){
	console.log(str);
});
