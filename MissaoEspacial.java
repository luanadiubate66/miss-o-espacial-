import java.util.Random;
import java.util.Scanner;

public class MissaoEspacial {
    private static final Scanner scanner = new Scanner(System.in);
    private static final Random random = new Random();

    private static int escolherPlaneta() {
        System.out.println("\nEscolha um planeta:");
        System.out.println("1. Planeta Azul");
        System.out.println("2. Planeta Vermelho");
        System.out.println("3. Planeta Roxo");

        while (true) {
            System.out.print("Destino (1, 2 ou 3): ");
            String entrada = scanner.nextLine().trim();
            if (entrada.equals("1") || entrada.equals("2") || entrada.equals("3")) {
                return Integer.parseInt(entrada);
            }
            System.out.println("Opcao invalida. Tente novamente.");
        }
    }

    public static void main(String[] args) {
        String[] nomes = {"", "Planeta Azul", "Planeta Vermelho", "Planeta Roxo"};
        String[] mensagens = {"", "Voce encontrou cristais de agua!",
                "Voce encontrou minerais raros!", "Voce encontrou energia espacial!"};

        int pontos = 0;
        int vidas = 3;
        int recursos = 0;

        System.out.println("==========================================");
        System.out.println("             MISSAO ESPACIAL");
        System.out.println("==========================================");
        System.out.print("Digite o nome do(a) astronauta: ");
        String nome = scanner.nextLine().trim();
        if (nome.isEmpty()) {
            nome = "Astronauta";
        }

        System.out.println("\nBem-vindo(a), " + nome + "! Sua missao e explorar 3 planetas");
        System.out.println("e coletar pelo menos 2 recursos para salvar a Terra.");

        for (int fase = 1; fase <= 3 && vidas > 0; fase++) {
            System.out.println("\n--- FASE " + fase + " DE 3 ---");
            int planeta = escolherPlaneta();
            System.out.println("\nNave chegando ao " + nomes[planeta] + "...");

            int evento = random.nextInt(3);
            if (evento == 0) {
                System.out.println(mensagens[planeta]);
                pontos += 10;
                recursos++;
                System.out.println("+10 pontos! Recurso coletado.");
            } else if (evento == 1) {
                System.out.println("Um campo de asteroides bloqueou seu caminho!");
                vidas--;
                System.out.println("Voce perdeu uma vida.");
            } else {
                System.out.println("Voce encontrou uma estrela de energia!");
                pontos += 5;
                System.out.println("+5 pontos bonus!");
            }

            System.out.println("Vidas: " + vidas + " | Pontos: " + pontos
                    + " | Recursos: " + recursos);
        }

        System.out.println("\n==========================================");
        System.out.println("             RESULTADO DA MISSAO");
        System.out.println("==========================================");
        System.out.println("Astronauta: " + nome);
        System.out.println("Pontuacao final: " + pontos);
        System.out.println("Recursos coletados: " + recursos);
        System.out.println("Vidas restantes: " + vidas);

        if (vidas > 0 && recursos >= 2) {
            System.out.println("\nMISSAO CONCLUIDA! Voce ajudou a salvar a Terra!");
        } else if (vidas <= 0) {
            System.out.println("\nFIM DE JOGO! Suas vidas acabaram.");
        } else {
            System.out.println("\nMISSAO NAO CONCLUIDA. Faltaram recursos para salvar a Terra.");
        }

        scanner.close();
    }
}
