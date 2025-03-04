<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Connect Four Game (C++)</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #1e272e;
            color: #ffffff;
            text-align: center;
        }
        .container {
            width: 80%;
            margin: 20px auto;
            background: #485460;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0px 0px 15px rgba(255, 255, 255, 0.2);
        }
        h1 {
            color: #fbc531;
        }
        h2 {
            color: #00a8ff;
            margin-top: 20px;
        }
        ul {
            list-style-type: none;
            padding: 0;
        }
        li {
            background: #2f3640;
            padding: 10px;
            margin: 5px 0;
            border-radius: 5px;
        }
        pre {
            background: #2f3640;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
            text-align: left;
            color: #fbc531;
        }
        footer {
            margin-top: 20px;
            padding: 10px;
            background: #353b48;
            color: white;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Connect Four Game (C++)</h1>
        <h2>Overview</h2>
        <p>A C++ implementation of the classic Connect Four game, developed for the Programming Fundamentals course.</p>
        
        <h2>Features</h2>
        <ul>
            <li>Two-Player Mode with Toss System</li>
            <li>6x7 Grid with Dynamic Updates</li>
            <li>Winning Condition Detection (Horizontal, Vertical, Diagonal)</li>
            <li>Game Draw Handling</li>
            <li>Menu System with Play, Credits, Instructions, Records, and Exit</li>
        </ul>
        
        <h2>Installation & Execution</h2>
        <pre>git clone https://github.com/AyaanHassanShah/Connect-Four-Game-Cpp.git</pre>
        <p>Open the project in Microsoft Visual Studio and run <code>CONNECT 4-PF LAB PROJECT.cpp</code>.</p>
        
        <h2>How to Play</h2>
        <p>Players take turns selecting a column (1-7) to drop their token. The first player to connect four in a row wins.</p>
        
        <h2>Example Gameplay</h2>
        <pre>
 1 2 3 4 5 6 7
 ---------------
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
 ---------------
Player 1 (Red) - Choose a column: 4
        </pre>
        
        <h2>License</h2>
        <p>MIT License</p>
    </div>
    
    <footer>
        <p>Syed Ayaan Hassan Shah | National University of Computer and Emerging Sciences</p>
    </footer>
</body>
</html>
