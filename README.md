# Color Sort Research

Runs the intake and collects the detected hue from the optical sensor every
10ms. Stores the numbers in a JSON array on the SD card. `analyze.py` takes the
data and graphs to easily view peaks for rings.

## Why?

To easily determine the right hue ranges for color sorting in varying lighting
enviornments.

## Usage

1. Make sure to configure your ports for intake and optical.
2. Format and SD Card to exFAT and insert into brain.
3. Run the program and feed it rings while its still collecting data.
4. When "Finished!", drag the JSON file from the SD card next to `analyze.py`.
5. Install `matplotlib` and run `analyze.py` for the graph
