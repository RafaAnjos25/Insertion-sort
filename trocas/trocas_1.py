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

# Dados das trocas
trocas_ordenados = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
trocas_invertidos = [1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000, 1_249_975_000]
trocas_aleatorios = [599_382_270, 601_576_182, 601_469_841, 598_604_058, 599_348_152, 599_377_963, 600_832_563, 598_678_682, 601_131_627, 601_624_632]

# Cálculo das médias
media_ordenados = np.mean(trocas_ordenados)
media_invertidos = np.mean(trocas_invertidos)
media_aleatorios = np.mean(trocas_aleatorios)

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
ax.set_title('Média da Quantidade de Trocas no Vetor (Insertion Sort)')
ax.set_ylabel('Quantidade de Trocas\n(Bilhões)')
ax.set_ylim([0, limite_y])  # Ajustando o limite do eixo y

# Adicionando os valores nos gráficos com a formatação correta
for i, v in enumerate(medias):
    ax.text(i, v + (0.05 * max_media), formatar_valores(v), ha='center', color='black')

# Salvando o gráfico como imagem
plt.tight_layout()
plt.savefig('grafico_Media_Quantidade_Trocas_Vetor_InsertionSort_formatado.png')

print("Gráfico salvo como 'grafico_Media_Quantidade_Trocas_Vetor_InsertionSort_formatado.png'")
