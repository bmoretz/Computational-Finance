#
# Tick Data Client (csv)
#

import q
import zmq
import datetime

header = 'time,symbol,price\n'

f = open( 'data.csv', 'a', 1 )
f.write( header )

context = zmq.Context()
socket = context.socket( zmq.SUB )
socket.connect( 'tcp://0.0.0.0:5566' )
socket.setsockopt_string( zmq.SUBSCRIBE, 'AAPL' )

while True:
	msg = socket.recv_string()
	symbol, price, = msg.split()
	t = datetime.datetime.now()
	print( str(t) + ' | ' + msg )
	f.write( str(t) + ',' + symbol + ',' + price + '\n')
