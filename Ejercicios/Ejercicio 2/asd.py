import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import random

def main():
	enes = range(1, 500)
	consumo = [(n) for n in enes]

	dataf1 = pd.DataFrame({'Consumo': consumo, 'Poblacion': enes})
	dataf1.astype(float)

	dataf1.plot(title='Consumo y poblacion', x='Poblacion')
	plt.ylabel('Consumo')
	plt.xlabel('Poblacion')

	plt.show()

main()