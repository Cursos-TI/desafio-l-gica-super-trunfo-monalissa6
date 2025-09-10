# Função para cadastrar uma carta
def cadastrar_carta():
    print("\n📇 Cadastro de Carta:")
    estado = input("Estado: ")
    codigo = input("Código da carta: ")
    nome = input("Nome da cidade: ")
    populacao = int(input("População: "))
    area = float(input("Área (km²): "))
    pib = float(input("PIB (em bilhões): "))
    pontos_turisticos = int(input("Número de pontos turísticos: "))

    densidade = populacao / area if area > 0 else 0

    return {
        "estado": estado,
        "codigo": codigo,
        "nome": nome,
        "populacao": populacao,
        "area": area,
        "pib": pib,
        "pontos_turisticos": pontos_turisticos,
        "densidade": densidade
    }

# Função para exibir uma carta
def exibir_carta(carta):
    print("\n📋 Carta:")
    for chave, valor in carta.items():
        print(f"{chave.capitalize()}: {valor}")

# Função para comparar duas cartas
def comparar_cartas(carta1, carta2, atributo):
    print(f"\n🔍 Comparando atributo: {atributo}")

    if atributo not in carta1 or atributo not in carta2:
        print("Atributo inválido.")
        return

    valor1 = carta1[atributo]
    valor2 = carta2[atributo]

    if atributo == "densidade":
        # Menor densidade vence
        if valor1 < valor2:
            vencedora = carta1
        elif valor2 < valor1:
            vencedora = carta2
        else:
            vencedora = None
    else:
        # Maior valor vence
        if valor1 > valor2:
            vencedora = carta1
        elif valor2 > valor1:
            vencedora = carta2
        else:
            vencedora = None

    if vencedora:
        print(f"\n🏆 Carta vencedora: {vencedora['nome']} ({atributo} = {vencedora[atributo]})")
    else:
        print("\n🤝 Empate!")

# Programa principal
print("=== Jogo de Cartas: Cidades do Brasil ===")
carta1 = cadastrar_carta()
carta2 = cadastrar_carta()

exibir_carta(carta1)
exibir_carta(carta2)

print("\n🎯 Atributos disponíveis para comparação: população, area, pib, pontos_turisticos, densidade")
atributo = input("Digite o atributo para comparação: ").strip().lower()

comparar_cartas(carta1, carta2, atributo)
