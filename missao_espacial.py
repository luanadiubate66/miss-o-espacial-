import random

PLANETAS = {
    "1": ("Planeta Azul", "Você encontrou cristais de água!", 10),
    "2": ("Planeta Vermelho", "Você encontrou minerais raros!", 10),
    "3": ("Planeta Roxo", "Você encontrou energia espacial!", 10),
}

def escolher_planeta():
    print("\nEscolha um planeta:")
    for numero, (nome, _, _) in PLANETAS.items():
        print(f"{numero}. {nome}")
    while True:
        escolha = input("Destino (1, 2 ou 3): ").strip()
        if escolha in PLANETAS:
            return PLANETAS[escolha]
        print("Opção inválida. Tente novamente.")

def jogar():
    pontos = 0
    vidas = 3
    recursos = 0

    print("=" * 42)
    print("       MISSÃO ESPACIAL")
    print("=" * 42)
    nome = input("Digite o nome do(a) astronauta: ").strip()
    if not nome:
        nome = "Astronauta"

    print(f"\nBem-vindo(a), {nome}! Sua missão é explorar 3 planetas")
    print("e coletar pelo menos 2 recursos para salvar a Terra.")

    for fase in range(1, 4):
        if vidas <= 0:
            break

        print(f"\n--- FASE {fase} DE 3 ---")
        planeta, mensagem, valor = escolher_planeta()
        print(f"\nNave chegando ao {planeta}...")

        evento = random.choice(["recurso", "obstaculo", "bonus"])
        if evento == "recurso":
            print(mensagem)
            pontos += valor
            recursos += 1
            print(f"+{valor} pontos! Recurso coletado.")
        elif evento == "obstaculo":
            print("Um campo de asteroides bloqueou seu caminho!")
            vidas -= 1
            print("Você perdeu uma vida.")
        else:
            print("Você encontrou uma estrela de energia!")
            pontos += 5
            print("+5 pontos bônus!")

        print(f"Vidas: {vidas} | Pontos: {pontos} | Recursos: {recursos}")

    print("\n" + "=" * 42)
    print("           RESULTADO DA MISSÃO")
    print("=" * 42)
    print(f"Astronauta: {nome}")
    print(f"Pontuação final: {pontos}")
    print(f"Recursos coletados: {recursos}")
    print(f"Vidas restantes: {vidas}")

    if vidas > 0 and recursos >= 2:
        print("\nMISSÃO CONCLUÍDA! Você ajudou a salvar a Terra! 🌎")
    elif vidas <= 0:
        print("\nFIM DE JOGO! Suas vidas acabaram.")
    else:
        print("\nMISSÃO NÃO CONCLUÍDA. Faltaram recursos para salvar a Terra.")

if __name__ == "__main__":
    jogar()
