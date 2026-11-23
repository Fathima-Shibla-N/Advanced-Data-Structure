#include <stdio.h>

int main() {
    int n, e, i, j, u, v, w, cost = 0;
    int parent[20], edges[50][3], temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++) {
        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    for(i = 0; i < e; i++) {
        for(j = i + 1; j < e; j++) {
            if(edges[i][2] > edges[j][2]) {
                for(int k = 0; k < 3; k++) {
                    temp = edges[i][k];
                    edges[i][k] = edges[j][k];
                    edges[j][k] = temp;
                }
            }
        }
    }

    printf("Edges in MST:\n");

    for(i = 0; i < e; i++) {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];

        if(parent[u] != parent[v]) {
            printf("%d - %d : %d\n", u, v, w);
            cost += w;

            int old = parent[u];
            for(j = 0; j < n; j++)
                if(parent[j] == old)
                    parent[j] = parent[v];
        }
    }

    printf("Minimum cost = %d", cost);
    return 0;
}
