#!/bin/bash

echo "simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a2=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a2=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1

echo "a1=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts  a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a1=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a1=1;a2=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a1=1;a2=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1

echo "a0=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a0=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a0=1;a2=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a0=1;a2=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1

echo "a0=1;a1=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a0=1;a1=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a0=1;a1=1;a2=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
echo "a0=1;a1=1;a2=1;a3=1;simulate;display" | ./nanotekspice resources/simple/decoder.nts a0=0 a1=0 a2=0 a3=0 inhibit=0 strobe=1
