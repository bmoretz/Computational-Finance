import pandas as pd
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

store = pd.HDFStore( 'data/index.h5' )

dax = store.select( "DAX" )

# daily quotes and log returns
def quotes_returns( data ):
	''' Plots quotes and returns. '''
	plt.figure( figsize = ( 9, 6 ) )
	plt.subplot( 211 )

	data[ 'Close' ].plot()

	plt.ylabel( 'daily returns' )
	plt.grid( True )
	plt.axis( 'tight' )

	plt.subplot( 212 )
	data[ 'Return' ].plot()
	plt.ylabel( 'daily log returns' )
	plt.grid( True )
	plt.axis( 'tight' )

quotes_returns( dax )