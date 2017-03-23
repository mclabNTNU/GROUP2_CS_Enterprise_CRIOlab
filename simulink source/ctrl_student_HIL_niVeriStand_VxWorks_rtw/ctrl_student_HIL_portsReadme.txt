	<portlist>
<inport> id="-1"  name = "u_in" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "y_in" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "psi_in" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "x_in" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "r_in" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "v_in" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "Desired sampling frequency" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "noise power position" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "noise power heading" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "u_dot_imu" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "enable noise" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "Guidance (CASE D)/k2 " width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "Guidance (CASE D)/mu1" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "Observer (CASE C)/L2" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "Observer (CASE C)/L1" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "Observer (CASE C)/L3" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/L2_continuous" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/PosXLeft" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/PosYLeft" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/PosXRight" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/PosYRight" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/ArrowUp" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/ArrowDown" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/R2_continuous" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/L1" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/R1" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/ArrowLeft" width = "1" datatype = "0"</inport>
<inport> id="-1"  name = "joystick/ArrowRight" width = "1" datatype = "0"</inport>
<outport> id = "-1" name = "u_true" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "psi_out" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "fater noise" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "eta_hat" width = "3" datatype = "22"</outport>
<outport> id = "-1" name = "nu_hat" width = "3" datatype = "22"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/X_d" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/N_d" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/Y_d" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/psi_0 " width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/x_0" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/y_0" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "tau to CSE mocell (only use for HIL testing)/integrator reset model" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "Observer (CASE C)/u_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/x_m" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "Observer (CASE C)/x_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/y_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/psi_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/v_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/r_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/bx_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/by_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/bpsi_hat" width = "1" datatype = "22"</outport>
<outport> id = "-1" name = "Observer (CASE C)/y_m" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "Observer (CASE C)/psi_m" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "Observer (CASE C)/x-error" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "Observer (CASE C)/y-error" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "Observer (CASE C)/psi_error" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "Tank (CASE B)/X" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "Tank (CASE B)/Y" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "Tank (CASE B)/Z" width = "1" datatype = "17"</outport>
<outport> id = "-1" name = "joystick/u_VSP1" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "joystick/alpha_VSP1" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "joystick/omega_VSP1" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "joystick/omega_VSP2" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "joystick/u_BT" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "joystick/alpha_VSP2" width = "1" datatype = "0"</outport>
<outport> id = "-1" name = "joystick/u_VSP2" width = "1" datatype = "0"</outport>
</portlist>
