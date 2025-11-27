#!/bin/bash

Tailnets=()
count=$(tailscale switch --list |wc -l)
active=$(tailscale switch --list |fgrep '\*')
list_output=$(tailscale switch --list |sed -z 's/\n/,/g')

#we ignore 1 because it's the heading of the tailscale switch output
for tn in $(seq 2 "$count"); do
  this=$(echo "$list_output" |cut -d , -f "$tn")
  Tailnets["$tn"]="$this"
  if [[ $this == *'*'* ]]; then
    active="$tn"
  fi
done

if [[ "$active" == "$count" ]]; then
  active=2
else
  ((active+=1))
fi

display=$(echo "${Tailnets[$active]}"|tr -s ' ' |cut -d ' ' -f 2)
id=$(echo "${Tailnets[$active]}"|tr -s ' ' |cut -d ' ' -f 1)

tailscale switch "$display"
notify-send "Switched to $display"
