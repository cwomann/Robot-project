/*tells the server to interpretate it all as a string of multiple lines*/
const char control_page[]  PROGMEM = R"html_file( 
<!DOCTYPE html>
<html>
    <script>
        function control_btn(btn_id) { 
            var xhttp = new XMLHttpRequest(); // it creats a new http request
            xhttp.open("GET", "control?control=" + btn_id, true); // exposes a function to be loaded when the server recieves the get request
            xhttp.send(); // http://192.168.0.106/control?control=btn_id 
        }
    </script>
  <head>
    <title>Controlo do robo</title>
    <style>
      .button {
      	height: 50px; 
        width: 120px;
        border: none;
        color: white;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 16px;
        margin: 4px 2px;
        cursor: pointer;
        background-color: #017c72;
      }   
      .button_quad {
        height: 75px; 
        width: 75px;
        border: none;
        color: white;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 16px;
        margin: 4px 2px;
        cursor: pointer;
        background-color: #4CAF50;
      }
      .button_STOP {
        height: 75px; 
        width: 75px;
        border: none;
        color: white;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 16px;
        margin: 4px 2px;
        cursor: pointer;
        background-color: #911000;
      } 
      .right {
          float: right;
      }   
    </style>
  </head>
  <body>
  
    <div style="text-align:center">
      <h1>ROBOT P117</h1>     
      
      <button id="AUTO" onclick="control_btn(this.id)" class="button"> AUTO </button>

      <br><br>
      
      <h2>Controller</h2>
      <button id="FWD" onclick="control_btn(this.id)" class = "button_quad" >FOARD</button>
      <br><br><br><br>
      <img hspace="10" style="padding-left: 5px">
      <button id="LFT" onclick="control_btn(this.id)" class = "button_quad">LEFT</button>
      <img hspace="20" style="padding-left: 10px">
      <button id="STP" onclick="control_btn(this.id)" class = "button_STOP">STOP</button>
      <img hspace="20" style="padding-left: 10px">
      <button id="RGT" onclick="control_btn(this.id)" class = "button_quad">RIGHT</button>
      <img hspace="10" style="padding-left: 5px">
      <br><br><br><br>
      <button id="REV" onclick="control_btn(this.id)" class = "button_quad button_quad">BACK</button>
      
    </div>
  </body>
</html>)html_file";
