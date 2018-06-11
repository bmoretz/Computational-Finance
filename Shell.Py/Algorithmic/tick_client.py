#
# Tick Data Client
#

import q
import zmq
import datetime

context = zmq.Context()
socket = context.socket( zmq.SUB )
socket.connect( 'tcp://0.0.0.0:5566' )
socket.setsockopt_string( zmq.SUBSCRIBE, 'AAPL' )

while True:
	msg = socket.recv_string()
	t = datetime.datetime.now()
	print( str(t) + ' | ' + msg )