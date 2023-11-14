# Ps_Group11_Assignment

### 1. Project Introduction & Application

#### 1.1 Model Introduction

​	The Gray-Scott model is a mathematical model used to describe chemical reactions and diffusion processes. It is a simplified example of a reaction-diffusion system and is often used to study how complex patterns form spontaneously in spatial systems. The model is particularly suitable for simulating patterns that occur in certain biological and chemical processes, such as marking on animal skin or the distribution of chemicals. This project aim at simulating the Gray-Scott model in order to study pattern formation in chemical and biological systems.

#### 1.2 Importance & Application

​	In biology, the Gray-Scott model is an important tool for studying how natural patterns like spots and stripes are formed on living organisms, such as animal skin. It provides a way to understand the biochemical processes underlying these complex patterns. 

​	In chemistry, this model demonstrates how complex spatial patterns can be created through simple chemical reactions and diffusion processes. This is critical for understanding certain types of chemical waves, helix formation and other nonlinear chemical phenomena.

​	In mathematic,  it is a typical example of the application of partial differential equations in simulating complex systems. It is a practical tool for students and professionals in the fields of mathematics and computational science to understand and practice concepts of numerical analysis and computational modeling.



### 2. Main Program

​	The main program is a simulation C++ program for simulating the Gray-Scott model.  It should initial some parameters  such as the diffusion of two chemical material (du and dv), feeding rate (F) and killing rate (k), as well as time steps and number of iterations before use it. This program including simulate step and write the current V value to a VTK file every iteration for visualization. After simulation, Calculating the proportion of grids whose value of V exceeds a certain threshold to the total number of grids. It is used in the program to distinguish areas where chemical concentrations are significant or high enough, which helps identify and analyze pattern formation. For example, in some modes, visible patterns or structures are formed only when the concentration of V exceeds a certain threshold.



### 3. Test Program

​	The test program is to prove that the main program is greatly complete the simulation and make sure the logic and data is correct, including three parts:

(0.1) Check that the type of the model parameters (F , k) matches that of the element type of the u and v vectors.

(0.2) Check that the variables u and v are the same size.

(0.3) Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.
