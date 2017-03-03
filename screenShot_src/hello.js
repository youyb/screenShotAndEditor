var sc = require('./build/Release/screencapture.node');

//var dir = "C:/work/ws/out/";
var save_dir = "/Users/yyb/out/";
var icon_dir = "/Users/yyb/out/SealTalk_Ent_Test.app/Contents/Resources/app";
var app = new sc.Main;

// console.log('image path: ' + app.screenCapture(dir));

app.screenCapture(save_dir, icon_dir, function(str){
	console.log(str);
});

