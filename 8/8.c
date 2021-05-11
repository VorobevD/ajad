#include <stdio.h>

int ver (int *t, int l, int tp){
    for(int i = 0; i < l; i++){
        if(t[i] == tp)
            return 0;
    }
    return 1;
}
int f (int v[],int nv,int n_of_v,int  l,int m,int m_v_1,int m_v_2,int g[][3],int r[][3] ) {
    while (!v[nv - 1]) {
        for (int i = 0; i < n_of_v + 1; i++) {
            for (int j = 0; j < l; j++) {
                if (g[j][0] == v[i]) {
                    if ((g[j][2] < m) && (ver(nv, n_of_v + 1, g[j][1]))) {
                        m = g[j][2];
                        m_v_1 = g[j][1];
                        m_v_2 = g[j][0];
                    }
                }
            }
        }
    }
    r[n_of_v][0] = m_v_2;
    r[n_of_v][1] = m_v_1;
    r[n_of_v][2] = m;
    n_of_v++;
    v[n_of_v] = m_v_1;
}


int main(int argc, char *argv[]) {
    FILE * file_1;
    FILE * file_2;
    if (file_1 == NULL) {
        return -1;
    }
    if (argc == 2) {
        file_1 = fopen(argv[1], "r");
        file_2 = fopen("output.txt", "w");
    }
    else if (argc >= 3) {
            file_1 = fopen(argv[1], "r");
            file_2 = fopen(argv[2], "w");
        }

    else
        {
        file_1 = fopen("input.txt", "r");
        file_2 = fopen("output.txt", "w");
    }

    int number_of_vertices, number_of_ribs, graph_type, length = 0;
    fscanf(file_1, "%d %d %d", &number_of_vertices, &number_of_ribs, &graph_type);
    int graph[number_of_ribs*2][3];

    while (!(feof(file_1))) {
        fscanf(file_1, "%d %d %d", &graph[length][0], &graph[length][1], &graph[length][2]);
        length++;
    }

    int l = length,  nv = number_of_vertices, vertices[nv];
    for (int i = 0; i < nv; i++)
        vertices[i] = 0;
    int r[l][3];
    for (int i = 0; i < l; i++){
        r[i][0] = 0;
        r[i][1] = 0;
        r[i][2] = 0;
    }


    int num_of_vertice = 0;
    vertices[num_of_vertice] = graph[0][0];

    int min = graph[0][2], min_vertice = graph[0][1],  min_vertice_2 = graph[0][0];
    f (vertices[num_of_vertice], nv, num_of_vertice, l, min, min_vertice, min_vertice_2, graph[number_of_ribs*2][3], r[l][3]);


    int summa = 0;
    for (int i = 0; i < l; i++) {
        if (r[i][0] == 0)
            break;
        summa+= r[i][2];
    }
    fprintf(file_2, "%d\n%d\n%d\n%d\n", summa,number_of_vertices,number_of_ribs,graph_type);
    for (int j = 0; j < length; j++) {
        fprintf(file_2, "%d %d %d\n", graph[j][0], graph[j][1], graph[j][2]);
    }
    fclose(file_1);
    fclose(file_2);
    return 0;
}
