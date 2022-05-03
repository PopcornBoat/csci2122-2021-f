#!/bin/bash 
HISTFILE=~/.bash_history
set -o history
echo "Using bash script to perform the same task as in Challenge1!"
# here starts the process
mkdir -p one/two/three this/that/theother us/them
touch one/{07kindhearted,17start} one/two/{01never,19history} one/two/three/{08spot,09today,10tame,18curious} this/{05gonna,15sulky} this/that/{06bike,11give,12expensive} this/that/theother/{04conscious,16you} us/02card us/them/{03spoil,13boot,14water,20up}
echo "tell me not to tell me what's for dinner" > one/two/01never
echo "these kids at the door" > us/02card
echo "every puppy you see, but not the flowers" > us/them/03spoil
echo "decisions make conscious efforts" > this/that/theother/04conscious
echo "take you out for a steak dinner" > this/05gonna
echo "all the way to town using only one leg and an expensive hat" > this/that/06bike
echo "people beatbox their way into my heart" > one/07kindhearted
echo "the difference between these two pictures" > one/two/three/08spot
echo "is the first day of your new life as a living thing" > one/two/three/09today
echo "the lions before you put your head in their mouth" > one/two/three/10tame
echo "me a hug and buy me dinner because you're making me hungry" > this/that/11give
echo "rings are expensive things and that's sad" > this/that/12expensive
echo "him out of the boat and save yourself" > us/them/13boot
echo "the garden, unless you're scared of flowers" > us/them/14water
echo "children really test the bounds of child abuse law" > this/15sulky
echo "should cook dinner for the one you love, especially if it's a puppy" > this/that/theother/16you
echo "picking flowers and sing me a song about not letting anything go, ever" > one/17start
echo "ity killed the cat, and that's sad" > one/two/three/18curious
echo "is boring, unless it's about puppies because puppies are awesome" > one/two/19history
echo "the creek without paddle will make me late for dinner" > us/them/20up
history | tail -n 23  > commands.hst


#check if commands are successfully executed
if [ $? -eq  0 ] 
then
	echo "Script execution successful"
	echo "This script also generates a command history as Challenge1 required"
else
	echo "Execution Failed!"
fi
