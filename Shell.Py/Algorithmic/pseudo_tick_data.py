#
# Tick Data Creation
#

import q
import zmq
import time
import random
import datetime

context = zmq.Context()
socket = context.socket( zmq.PUB )
socket.bind( 'tcp://0.0.0.0:5566' )

AAPL = 100.

while True:
	AAPL += random.gauss( 0, 1 ) * .5
	msg = 'AAPL {:.4f}'.format( AAPL )
	socket.send_string( msg )
	print( msg )
	q( msg )
	time.sleep( random.random() * 2 )