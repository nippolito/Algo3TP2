import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random


k = pd.read_csv("probarN.csv", delimiter=',')




indxM = []
for i in range(10,500):
	if i % 5 == 0:
		indxM.append(i)
#fb.plot()
#bp.plot()
plt.plot(k['y'],k['x'],'b.', label='\nM=1000 \nCant.RP = 1000 \nK=100')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
for label in legend.get_texts():
    label.set_fontsize('medium')

for label in legend.get_lines():
    label.set_linewidth(1.5)

plt.ylabel("Tiempo en segundos")

plt.xlabel("Cantidad de Ciudades")
plt.show()
