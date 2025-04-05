# Head for the first deployment of **PIR Array Project** 

## Introduction

In this project `Localization Indoor Using PIR Array`, we already have:

- Reliable PIR Array hardware (5 PIRs) + Firmware. 
- Machine Learning Model (Precision of 86.41%, based on Duc and Cong's report in last semester).

Now we just need final product to display realtime location base on PIR Array stream data, bring 
project to life with end-user features.

## Architecture

We will have 3 main blocks:

- `PIR Array hardware`: Collects and streams PIR Array realtime data to server.

- `Server with UI`: receives stream data, seperate them into time-based slices and delegates `ML Model` to process.

- `ML Model`: belongs to Cong & Duc, receives PIR data slices and give output as current human position (X, Y or position index).


