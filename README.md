# Myth VCV modules

I built these two modules to simplify creating some generative sequences and sounds.

## Mavka
Mavka is a simple oscillator with four waveforms. You can control the level of each waveform either with knobs
or with CV inputs. CV value will be added to the knob value.

## Molphar
Molphar is a sequencer with the ability to define probability per step. There are three 8-step sequences in Molphar.

Under the sequence rows, there is a row of probability controls.
Each probability knob sets the probability for the corresponding step in each sequence. Probabilities can be controlled
via CV inputs as well — if there is a CV in the input, then the corresponding knob controls nothing.

Probability inputs expect the value from 0 to +1V. I may change it to work within the 0..10V later, since it seems logical to do.

The light near the step will turn on if the step is active. If the step is current but not active because of probability,
the light will be red; otherwise green. If the step is not active, the corresponding output will be outputting
CV from the previously active step.

The row below probabilities is the gates row. It will output +10V in case the corresponding step is active.

On the bottom left, there is a track input and knob. It controls which sequence row will be routed to the
Out output. Use any value from 0V to +1V exclusive to route the first row, from +1V to +2V exclusive to route
the second row, and +2V to route the third row.

Trig output outputs +10V trigger CV for every active step.

Outputs 1, 2, and 3 output values from the corresponding row.

Output outputs CV configured by knobs in a row specified by the "track" knob or CV.

Tip: set up the third row to voltages from 0V to +1.9V, and connect Out 3 to the Track input. Now the third row controls which row will be routed to the Out output. If you play with probabilities, you will achieve
generative melodies with some repetitions and some random things.
