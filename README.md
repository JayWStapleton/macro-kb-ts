# tailscale-keyboard
A macro keyboard that flips through my available tailnets 

I have this wired up with two keyswitches wired to an Arduino pro micro. Both switches are tied to ground on one pin, and on pins 9 and 15 respectively though that was arbitrary. 

The keypress sends CTRL-SHIFT-ALT-T and CTRL-SHIFT-ALT-R which I've mapped one to run /home/bin/tailscaleswitch.sh in my desktop, the other one is for future use. 

On my machine (PopOS/Gnome) it is under settings/keyboard/custom shortcuts

![tskeyboard](images/tskb.jpeg)

