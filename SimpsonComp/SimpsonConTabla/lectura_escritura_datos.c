
    FILE *fp;
    char ch;
    fp = fopen("tabla.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
    }

    //contador de filas
    int filas=0;
    char c;
    int maxValues = 0;
	int columnas;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen("tabla.dat","r");
    double x[filas];
    double y[filas]; //Termino independiente


    //Cargo los datos leidos en el array
    int xi=0;
    int yi=0;
    int j=0;
    int i;
	for(i = 0; i < filas; i++) {
		j = 0;
		
		do {
			if(j==0)
			{
				 fscanf(fp, "%lf", &(x[xi]));
				 xi++;
				 j++;
			}else{
				 fscanf(fp, "%lf", &(y[yi]));
				 yi++;
			}
		} while((c = fgetc(fp)) != '\n');
		
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA TABLA SON:\n");
    	
    for(i=0;i<filas;i++){
	        printf( "%lf \t %lf", x[i], y[i]);
	        printf("\n");
	}
	

	
	//ejemplo de como escribir en archivo
	/*
	    FILE * file;
        file= fopen("matriz_1.dat", "w");
		
      for(i=0;i<3;i++){
            fprintf(file, "%lf	%lf	%lf	%lf\n", m[i][0],m[i][1],m[i][2],m[i][3]);
        }
        
      */  
	

        
 

