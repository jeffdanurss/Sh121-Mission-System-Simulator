# Sh121-Mission-System-Simulator

A high-performance, real-time mission system simulation written in C, inspired by the **N036 Byelka (Sh121)** radar suite. This project demonstrates core principles of Avionics Engineering, Cybernetics, and Critical Systems.

## Purpose
The goal of this project is to simulate the signal processing logic of a 5th-generation AESA radar. It addresses the challenge of detecting low-observable (stealth) targets by balancing transmission power (LPI mode) and signal-to-noise ratios (SNR).

## Technical Features
* **Deterministic Real-Time Loop:** Implemented using microsecond-precision timing to simulate an RTOS environment.
* **Non-blocking I/O:** Hardware-level interrupt simulation for real-time pilot input (Frequency hopping/Mode switching).
* **Signal Integrity:** Simulation of Gaussian noise and signal degradation.

## Mathematics & Physics Applied
* **Radar Range Equation:** Implementation of power density calculations involving RCS (Radar Cross Section), Gain, and Wavelength.
* **Linear Algebra:** Vector-based distance and velocity tracking in a 3D coordinate system.
* **Probability & Statistics:** Modeling of the noise floor and signal detection thresholds using stochastic variables.

## Installation & Usage

### Prerequisites
* A Linux-based environment (WSL2, Ubuntu, or similar).
* GCC Compiler and Make.

### Compilation
Clone the repository and run the Makefile:
```bash
git clone [https://github.com/YOUR_USERNAME/Sh121-Mission-System-Simulator.git](https://github.com/YOUR_USERNAME/Sh121-Mission-System-Simulator.git)
cd Sh121-Mission-System-Simulator
make
```
### Running the Simulator
Once compiled, execute the binary:
```bash
./sh121_sim
```
## How to Interact (Operator Interface)

The simulator runs in a **non-blocking real-time loop**. You can interact with the Sh121 control system using the following keys:

* **`f`**: Toggles between **LPI (Stealth Mode)** and **High Power Mode**.
    * **LPI Mode:** Reduces transmission power to avoid detection by the enemy Rafale's SPECTRA electronic warfare suite.
    * **High Power:** Maximizes detection range but makes the Su-57 platform visible to enemy Electronic Support Measures (ESM).
* **`Ctrl + C`**: Safely aborts the mission and exits the simulation.

---

## Technical Analysis

The core of this software is the **Signal-to-Noise Ratio (SNR)** calculation. As an engineer, you can observe how the signal power follows the **Inverse Fourth Power Law** ($1/R^4$):

> [!IMPORTANT]
> This means that doubling the distance to the target reduces the returned signal strength by **16 times**.

This physical phenomenon is why stealth detection remains a critical challenge in modern avionics and electronic warfare.

---

## Academic Context

This project was developed as a practical application of **Cybernetics and Systems Engineering** principles.

* **Author:** Jefferson Llerena
* **Fields of Interest:** Embedded Systems, Avionics, Signal Processing, and Defense Technology.
