#pragma once
#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
    <title>ESP Pushbutton Web Server</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body {
            font-family: Arial;
            text-align: center;
            margin: 0 auto;
            padding-top: 30px;
        }
        .button {
            padding: 10px 20px;
            font-size: 24px;
            text-align: center;
            outline: none;
            color: #fff;
            background-color: #003265;
            border: none;
            border-radius: 5px;
            box-shadow: 0 6px #999;
            cursor: pointer;
            -webkit-touch-callout: none;
            -webkit-user-select: none;
            -khtml-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
            user-select: none;
            -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
        }
        .button:hover {
            background-color: #091b44;
        }
        .button:active {
            background-color: #091b44;
            box-shadow: 0 4px #666;
            transform: translateY(2px);
        }
    </style>
</head>
<body>
    <h1>AGV Version 2.0</h1>

    <p align="middle">__________________________</p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('forward');" 
                ontouchstart="toggleCheckbox('forward');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');">/\
        </button>
    </p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('left');" 
                ontouchstart="toggleCheckbox('left');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');"><
        </button>
        <button class="button" onmousedown="toggleCheckbox('off');" 
                ontouchstart="toggleCheckbox('off');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');">STOP
        </button>
        <button class="button" onmousedown="toggleCheckbox('right');" 
                ontouchstart="toggleCheckbox('right');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');">>
        </button>
    </p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('back');" 
                ontouchstart="toggleCheckbox('back');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');">\/
        </button>
    </p>

    <p align="middle">__________________________</p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('HORN');" 
                ontouchstart="toggleCheckbox('HORN');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');">HORN
        </button>
    </p>

    <p align="middle">__________________________</p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('red');" 
                ontouchstart="toggleCheckbox('red');" 
                onmouseup="toggleCheckbox('red');" 
                ontouchend="toggleCheckbox('red');">RED
        </button>
        <button class="button" onmousedown="toggleCheckbox('yellow');" 
                ontouchstart="toggleCheckbox('yellow');" 
                onmouseup="toggleCheckbox('yellow');" 
                ontouchend="toggleCheckbox('yellow');">YELLOW
        </button>
        <button class="button" onmousedown="toggleCheckbox('green');" 
                ontouchstart="toggleCheckbox('green');" 
                onmouseup="toggleCheckbox('green');" 
                ontouchend="toggleCheckbox('green');">GREEN
        </button>
    </p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('cyan');" 
                ontouchstart="toggleCheckbox('cyan');" 
                onmouseup="toggleCheckbox('cyan');" 
                ontouchend="toggleCheckbox('cyan');">CYAN
        </button>
        <button class="button" onmousedown="toggleCheckbox('blue');" 
                ontouchstart="toggleCheckbox('blue');" 
                onmouseup="toggleCheckbox('blue');" 
                ontouchend="toggleCheckbox('blue');">BLUE
        </button>
        <button class="button" onmousedown="toggleCheckbox('pink');" 
                ontouchstart="toggleCheckbox('pink');" 
                onmouseup="toggleCheckbox('pink');" 
                ontouchend="toggleCheckbox('pink');">PINK
        </button>
    </p>

    <p align="middle">
        <button class="button" onmousedown="toggleCheckbox('ledoff');" 
                ontouchstart="toggleCheckbox('ledoff');" 
                onmouseup="toggleCheckbox('off');" 
                ontouchend="toggleCheckbox('off');">OFF
        </button>
    </p>

    <h1>Viel Spaß mit deinem Auto :)</h1>

    <script>
        function toggleCheckbox(x) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/" + x, true);
            xhr.send();
        }
    </script>
</body>
</html>
)rawliteral";
