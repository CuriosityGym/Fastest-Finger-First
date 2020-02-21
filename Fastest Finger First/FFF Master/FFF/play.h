const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <!-- manual = https://www.google.com/search?q=css+center+body+content&oq=css+center+body+content&aqs=chrome..69i57j0l3.9119j0j7&sourceid=chrome&ie=UTF-8 -->
<style>
  body{
    font-family: arial;
  }
  h4{
    text-decoration: underline;
  }
.leftshift20 {
  margin-left:6%;
}
#rcorners1 {
float: left;
  border-radius: 25px;
  background: #FF5533;
  padding: 20px;
  width: 180px;
  height: 140px;  
}
#rcorners2 {
float: right;
  border-radius: 25px;
  background: #64FF33;
  padding: 20px;
  width: 180px;
  height: 140px;  
}

#rcorners3 {
float: left;
border-radius: 25px;
  background: #3342FF;
  padding: 20px;
  width: 180px;
  height: 140px;    
}
#rcorners4 {
float: right;
 border-radius: 25px;
  background: #FCFF33;
  padding: 20px;
  width: 180px;
  height: 140px;  
}
.logo{
  padding:10px;
}
.pageheader{
  text-decoration: underline;
  margin-top:25px;
  margin-bottom: 25px;
}
.mybox{
  /*border:2px solid #777;*/
  background-color:#eee;
  padding:10px;
  width:80%;
  border:1px solid #ccc;
  margin:0 auto;
  margin-bottom:20px;
  text-align: left;
}
.row2{
  margin-top:50px;
}
.right{
  float:right;
}
#container{
  text-align: center;
}
#container_row{
  display: inline-block;
  /*border:1px solid red;*/
  width:90%;
}

.teamname{
  border-right:1px solid #ccc;
  padding:10px;
  margin-right:30px;
  font-weight: bold;
}
.timevalue{
  border-right:1px solid #ccc;
  padding:10px;
}
.optionvalue{
 padding:10px; 
}
.color0{
  color:#FA2A00;
}
.color1{
  color:#777777 ;
}
.color2{
  color:#2B879E;
}
.color3{
  color:#009900;
}
/*#loading{
  display:inline;
}*/
</style>
</head>
<body>

     
<!-- <p id="rcorners2">Device2 Time =</p>
<h1 id="Time">0</h1>    
<p id="rcorners3">Device3 Time =</p>
<p id="rcorners4">Device4 Time =</p> -->
<!-- <div id = "loading">
<h1>
  Loading Screen
</h1>  
  </div> -->

<div id = "container">
  <div id = "container_row"> 
    <img class = "logo" src = "https://curiositygym.com/wp-content/uploads/2016/08/CG8PC.png"/>
<h1 class = "pageheader">Fastest Finger First</h1>

<div id = "0box" class = "mybox">
  <span class = "teamname color0">Team A</span>
  <span id = "A_time" class="timevalue">Time =  </span>
  <span class="optionvalue" id = "A_option">Option 
  = </span>
</div>  
<div id = "1box" class = "mybox">
  <span class = "teamname color3">Team B</span>
  <span id = "B_time" class="timevalue">Time =  </span>
  <span class="optionvalue" id = "B_option">Option = </span>
</div>  
<div id = "2box" class = "mybox">
  <span class = "teamname color2">Team C</span>
  <span id = "C_time" class="timevalue">Time =  </span>
  <span class="optionvalue" id = "C_option">Option = </span>
</div>  
<div id = "3box" class = "mybox">
  <span class = "teamname color1">Team D</span>
  <span id = "D_time" class="timevalue">Time =  </span>
  <span class="optionvalue" id = "D_option">Option = </span>
</div>
</div>
</div>
 <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js">
 </script>
 <script type="text/javascript">
      var startTime = new Date();
      var startTime = startTime.getTime();
        // var receivedOptions = new Array();
        // var receivedTimes = new Array();
        // receivedOptions.push("A1");
        // receivedTimes.push("10:20");

        // receivedOptions.push("B1");
        // receivedTimes.push("10:21");

        // receivedOptions.push("C1");
        // receivedTimes.push("10:20");

        // receivedOptions.push("D1");
        // receivedTimes.push("10:21");

        // document.write (receivedOptions);
        // document.write("----------")
        // document.write (receivedTimes);

        // var ignoreCount = 0;
      var onceOnly = true;
      var onceOnlyA = true;
      var onceOnlyB = true;
      var onceOnlyC = true;
      var onceOnlyD = true;
       var teamList = [];
       // teamList.sort((a, b) => (a.color < b.color) ? 1 : -1);
     //  var e = {data:"D3"};
     // onmessage(e);
     //  var e = {data:"A2"};
     // onmessage(e);
     // var e = {data:"A2"};
     // onmessage(e);
     // var e = {data:"A1"};
     // onmessage(e);
     //  var e = {data:"A1"};
     // onmessage(e);
     // var e = {data:"A2"};
     // onmessage(e);
     // var e = {data:"B1"};
     // onmessage(e);
     //  var e = {data:"C1"};
     // onmessage(e);
     //   var e = {data:"D2"};
     // onmessage(e);
     function getDisplayOption(actualOption){
      if (actualOption == "A1" || actualOption == "B1" || actualOption == "C1" || actualOption == "D1")
        return "A";

      if (actualOption == "A2" || actualOption == "B2" || actualOption == "C2" || actualOption == "D2")
        return "B";

      if (actualOption == "A3" || actualOption == "B3" || actualOption == "C3" || actualOption == "D3")
        return "C";

      if (actualOption == "A4" || actualOption == "B4" || actualOption == "C4" || actualOption == "D4")
        return "D";
     }
     function performExecute(teamName,option){
        var eventDate = new Date();
        var eventTime = eventDate.getTime();
        var timeTaken = eventTime - startTime;
       // https://stackoverflow.com/questions/21294302/converting-milliseconds-to-minutes-and-seconds-with-javascript
        // console.log(e.data);
         // $("#"+numDiv+"_option").html("Option = A");
         // $("#"+numDiv+"_time").html("Time = "+timeTaken/1000);
         var teamData = {time: timeTaken/1000, teamName: teamName,option:option};
         teamList.push(teamData);
     }
      var connection = new WebSocket('ws://'+location.hostname+':81/', ['arduino']);
      connection.onmessage = function (e) {
        // function onmessage (e){
        if(onceOnly) {
        if (e.data == "incomingPacket") {
        } else {
          // ignoreCount ++;
          
          // if (ignoreCount < 50){
          //   console.log("ignoring "+ignoreCount);
          //   document.getElementById("loading").style.display = "block";
          //   document.getElementById("container").style.display = "none";
          //   return;
          // } 
          // else{
            //  document.getElementById("loading").style.display = "none";
            // document.getElementById("container").style.display = "block";
          // }
// document.getElementById("loading").style.display = "block";
//             document.getElementById("container").style.display = "none";
         

        // console.log(e.data == "A1");
        // console.log(typeof(e.data))
        // console.log(e.data=="incomingPacket");
        // console.log(e.data);
        // console.log(typeof(secondsDifference));
        if (onceOnlyA)
        if(e.data == "A1" || e.data == "A2" || e.data == "A3" || e.data == "A4") { 
          performExecute("A",getDisplayOption(e.data));
         onceOnlyA = false;
        }
        if (onceOnlyB)
         if(e.data == "B1" || e.data == "B2" || e.data == "B3" || e.data == "B4") { 
          performExecute("B",getDisplayOption(e.data));
         onceOnlyB = false;
        }
        if (onceOnlyC)
         if(e.data == "C1" || e.data == "C2" || e.data == "C3" || e.data == "C4") { 
          performExecute("C",getDisplayOption(e.data));
         onceOnlyC = false;
        }

        if (onceOnlyD)
         if(e.data == "D1" || e.data == "D2" || e.data == "D3" || e.data == "D4") { 
          performExecute("D",getDisplayOption(e.data));
         onceOnlyD = false;
        }

  if (!onceOnlyA && !onceOnlyB && !onceOnlyC && !onceOnlyD){
            console.log("preparing html");
            onceOnly = false;
            var colorNumber = 0;
          
            for(var i = 0;i<4;i++){ 
                if(teamList[i].teamName == "A")
            colorNumber = 0;
            if(teamList[i].teamName == "B")
            colorNumber = 3;
            if(teamList[i].teamName == "C")
            colorNumber = 2;
            if(teamList[i].teamName == "D")
            colorNumber = 1;
            
             var myinnerhtml = '#'+(i+1)+'<span class = "teamname color'+colorNumber+'">Team '+teamList[i].teamName+'</span>';
             myinnerhtml += '<span id = '+teamList[i].teamName+'_time class=timevalue>Time = '+teamList[i].time+' </span>';
             myinnerhtml += '<span id = '+teamList[i].teamName+'one_option class=optionvalue>Option = '+teamList[i].option+' </span>';
             document.getElementById(i+"box").innerHTML = myinnerhtml;
}

            // document.getElementById("onebox").innerHTML = myinnerhtml;
            // document.write(teamList[1].teamName);
            // document.write(teamList[2].teamName);
            // document.write(teamList[3].teamName);
          }

        }

        }
      };
      </script>
</body>
</html>

)=====";
