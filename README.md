<div align="center">
  <img src="img/fdf.png" alt="Logo" width="150" height="150">
  <h2>42 FDF PROJECT</h2>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge"/></a>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/badge/circle-2-magenta?style=for-the-badge"/></a>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/badge/42-Evaluation-red?style=for-the-badge"/></a>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/github/last-commit/emre-mr246/42_ring2_fdf?style=for-the-badge"/></a>
    <a href="https://42istanbul.com.tr/"><img src="https://img.shields.io/badge/42-ISTANBUL-white?style=for-the-badge"/></a>
   
<h4>
    <a href="https://github.com/emre-mr246/42_ring2_fdf/issues">❔ Ask a Question</a>
  <span> · </span>
    <a href="https://github.com/emre-mr246/42_ring2_fdf/issues">🪲 Report Bug</a>
  <span> · </span>
    <a href="https://github.com/emre-mr246/42_ring2_fdf/issues">💬 Request Feature</a>
</h4>
</div>

## Introduction 🚀

The "fdf" project challenges students to create a graphical representation of a landscape using a provided dataset of coordinates. This project is a fundamental part of the 42 school curriculum, aiming to develop skills in parsing files, working with graphics libraries, and understanding 3D representations.

Note: This project is intended for Linux systems. For running on macOS, modifications to the Makefile and adjustments in the MinilibX library are required.

## Objective 🎯

The objective of the "FDF" project is to generate a wireframe representation of a terrain based on coordinates provided in a file. This involves parsing the file to extract coordinate data, transforming these coordinates into a 3D space, and using a graphics library to draw lines between points to visualize the terrain.

## Line Drawing Algorithm 🧠

Utilizing the Bresenham line drawing algorithm as a foundation, I streamlined the slope calculation process by incorporating both the starting and ending points of the line into the function. Additionally, I enhanced the algorithm with anti-aliasing. Leveraging these enhancements, I have crafted a remarkably concise algorithm that rivals the functionality of more intricate counterparts, such as Xiaolin Wu's algorithm.

## Features 🔍
- 5 different perspectives
- Custom Color Mode: Set the color as you like by pressing the C, V, and B keys, and then paint any part of the drawing at your desired height using the G and H keys.
- Height-Based Color Mode: Color intensity increases or decreases based on height.
- Rotation Modes: Rotate around the model’s own axis or the camera axis.
- Anti-Aliasing
- Zoom in/out
- Rotate the model
- Flatten the model
- Increase/decrease model height
- View the model's properties live from the menu
- Move the model using the WASD keys
- Reset everything or turn off the custom color mode

## Image 📸

![](img/julia.png)

## Usage 🔍

1. In the project's main directory, compile the library using the `make` command.
   `$ make bonus` 

2. You can run the program with the following command:
   `$ ./fdf_bonus maps/pyramide.fdf` 
    
