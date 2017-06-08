import json
import zmq

ctx = zmq.Context()

sub = ctx.socket(zmq.SUB)
sub.connect('tcp://localhost:5559')

sub.setsockopt(zmq.SUBSCRIBE, '')

t_max = 0.5
t = 0

while t < t_max:
    message = json.loads(sub.recv())
    t = message[0]['value']
    print t, 'recv', message[0]

print 'exit'
