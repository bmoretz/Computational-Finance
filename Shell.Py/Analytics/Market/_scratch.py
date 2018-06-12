import math
import pandas as pd
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from scipy.stats import norm

store = pd.HDFStore( 'data/index.h5' )

dax = store.select( "DAX" )

def dN( x, mu, sigma ):
	''' Probability density function of a normal random variable x.

	Parameters
	================
	mu: float
		expected value

	sigma: float
		standard deviation

	Returns
	================

	pdf: float
		value of probability density function
	'''

	z = ( x - mu ) / sigma
	pdf = np.exp( -0.5 * z **2 ) / math.sqrt( 2 * math.pi * sigma ** 2 )

	return pdf

# daily quotes and log returns
def quotes_returns( data ):


	''' Plots quotes and returns. '''
	plt.figure( figsize = ( 9, 6 ) )
	plt.title( 'DAX Index [2004, 2014]' )

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

def return_histogram( data ):

	''' Plots a histogram of the returns '''
	plt.figure( figsize=( 9, 5 ) )
	
	x = np.linspace( min( data[ 'Return' ] ), max( data[ 'Return' ] ), 100 )
	plt.hist( np.array( data[ 'Return' ] ), bins = 100, normed = True, label = 'Returns' )

	mu = np.mean( data[ 'Return' ] )
	sigma = np.std( data[ 'Return' ] )

	y = dN( x, mu, sigma )
	plt.plot( x, y, linewidth = 2, label = 'Fitted Normal Curve' )
	
	sd_p1 = mu + sigma
	plt.vlines( x = sd_p1, ymin=0, ymax= dN( sd_p1, mu, sigma ), color = 'R', linestyles = 'dashed', linewidth= 3.0 )

	sd_m1 = mu - sigma
	plt.vlines( x = sd_m1, ymin=0, ymax= dN( sd_m1, mu, sigma ), color = 'R', linestyles = 'dashed', linewidth= 3.0, label = '+/- 1 Std. Dev' )

	dev_1 = data[ ( ( data[ 'Return' ] >= sd_m1 ) & ( data[ 'Return' ] <= sd_p1 ) ) ]
	dev_pct = len( dev_1 ) / len( data )

	plt.xlabel( 'log returns' )
	plt.ylabel( 'frequency/probabliity' )
	plt.title( 'Returns +/- 1 Standard Deviation: {0:.0%}'.format( dev_pct ) )

	plt.legend()
	plt.grid( True )

def realized_volatility( data ):
	''' Plots the realized volatility. '''
	plt.figure( figsize=( 9,5 ) )
	data[ 'Rea_Var' ].plot()
	plt.ylabel( 'realized volatility' )
	plt.grid( True )


quotes_returns( dax )
return_histogram( dax )
realized_volatility( dax )

plt.show()