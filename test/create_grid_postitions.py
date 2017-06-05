import numpy as np
import json

n = 5

pos = []

for j, z in enumerate(np.linspace(-1., 1., n)):
    for i, y in enumerate(np.linspace(-1., 1., n)):
        for i, x in enumerate(np.linspace(-1., 1., n)):
            pos.append([x, y, z, 1. / n, 1. / n, 1. / n])

with open('grid_positions.json', 'w+') as f:
    json.dump(pos, f)
