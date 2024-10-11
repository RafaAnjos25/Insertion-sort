import matplotlib.pyplot as plt
import numpy as np

# Função para formatar os valores com abreviações
def formatar_valores(valor):
    if valor >= 1_000_000_000:
        return f'{valor/1_000_000_000:.2f}B'  # Bilhões
    elif valor >= 1_000_000:
        return f'{valor/1_000_000:.2f}M'  # Milhões
    elif valor >= 1_000:
        return f'{valor/1_000:.2f}K'  # Milhares
    else:
        return str(valor)

# Dados das comparações
comparacoes_ordenados = [49_999]  # Única comparação para vetor ordenado
comparacoes_invertidos = [1_250_024_999]  # Única comparação para vetor invertido
comparacoes_aleatorios = [598_773_522, 600_407_340, 601_578_919, 600_782_308, 601_280_802, 
                          599_861_648, 597_922_189, 596_513_395, 598_881_567, 601_080_360, 
                          604_766_117]  # Vários valores para vetor aleatório

# Cálculo das médias
media_ordenados = np.mean(comparacoes_ordenados)
media_invertidos = np.mean(comparacoes_invertidos)
media_aleatorios = np.mean(comparacoes_aleatorios)

# Preparando os dados para o gráfico
categorias = ['Vetor com\n50.000 números\nordenados', 
              'Vetor com\n50.000 números\ninvertidos', 
              'Vetor com\n50.000 números\naleatórios']
medias = [media_ordenados, media_invertidos, media_aleatorios]

# Calculando o limite do eixo Y (20% maior que o valor máximo)
max_media = max(medias)
limite_y = max_media * 1.2

# Criando o gráfico de linha
fig, ax = plt.subplots()
ax.plot(categorias, medias, marker='o', color='black', linestyle='-', linewidth=2)

# Títulos e rótulos
ax.set_title('Média da Quantidade de Comparações no Vetor (Insertion Sort)')
ax.set_ylabel('Quantidade de Comparações')
ax.set_ylim([0, limite_y])  # Ajustando o limite do eixo y

# Adicionando os valores nos gráficos com a formatação correta
for i, v in enumerate(medias):
    ax.text(i, v + (0.05 * max_media), formatar_valores(v), ha='center', color='black')

# Salvando o gráfico como imagem
plt.tight_layout()
plt.savefig('grafico_Media_Quantidade_Comparacoes_Vetor_InsertionSort_formatado.png')

print("Gráfico salvo como 'grafico_Media_Quantidade_Comparacoes_Vetor_InsertionSort_formatado.png'")
