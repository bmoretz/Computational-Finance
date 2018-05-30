import datetime
import pandas as pd
pd.core.common.is_list_like = pd.api.types.is_list_like
from pandas_datareader import data as pdr
import fix_yahoo_finance as yf
import numpy as np

yf.pdr_override() 

pd.set_option('io.hdf.default_format','table')
store = pd.HDFStore( 'data/index.h5' )

# SPX : ^GSPC
# DAX : ^GDAXI

trading_days = 252
symbols = { "SPX":"^GSPC", "DAX":"^GDAXI" }

symbol = "DAX"
start = datetime.datetime( 2004, 9, 30 )
end = datetime.datetime( 2014, 9, 30 )

index = pdr.get_data_yahoo(symbols[ symbol ], 
						start,
						end,
						as_panel = False,
						auto_adjust = True)

# Logrithmic Returns
index[ 'Return' ] = np.log( index[ 'Close' ] / index[ 'Close'].shift( 1 ) )

# Realized Volatility ( eg. as defined for variance swaps )
index[ 'Rea_Var' ] = trading_days * np.cumsum( index[ 'Return' ] ** 2 ) / np.arange( len( index ) )
index[ 'Rea_Vol' ] = np.sqrt( index[ 'Rea_Var' ] )

# Remove Holidays/Market Closes
index = index.dropna()

store.append( symbol, index, format='table', data_columns = True )