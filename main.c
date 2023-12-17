#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    unsigned char red, green, blue;
} RGBP;

typedef struct {
    int w, h, r;
    RGBP **px;
} RGBImage;

RGBImage createImage(int width, int height, int resolution);
void initializeRandom(RGBImage *image);
void initializeFromInput(RGBImage *image);
void initializeFromFile(RGBImage *image, const char *filename);
void extractComponent(RGBImage *input, RGBImage *output, char component);
void applyFilter(RGBImage *input, RGBImage *output, char filter);




int main(int argc, char const *argv[]) {
	int width, height, resolution;
	printf("Enter width, height, and resolution : ");
    scanf("%d %d %d", &width, &height, &resolution);
    createImage(width, height, resolution);
    RGBImage OrigImg = createImage(width, height, resolution);
    printf("Whats methode you choose : \n1 - Random elemnts\n2 - From Input\n3 - From File\n");
    int choix = 1;
    scanf("%d", &choix);
    switch(choix){
    	case 1: initializeRandom(&OrigImg);
    		break;
    	case 2: initializeFromInput(&OrigImg);
    		break;
    	case 3: 
    		initializeFromFile(&OrigImg, "data.ppm");
    		break;
    }

	RGBImage processedImage = createImage(width, height, resolution);
    extractComponent(&originalImage, &processedImage, 'r');

	return 0;
}

void initializeRandom(RGBImage *OrigImg){
	srand(time(NULL));
	for(int i = 0; i < OrigImg->h * OrigImg->r - 1; i++){
		for(int j = 0; j < OrigImg->w * OrigImg->r - 1; j++){
			OrigImg->px[i][j].red = rand() % 256;
			OrigImg->px[i][j].green = rand() % 256;
			OrigImg->px[i][j].blue = rand() % 256;
		}
	}
}

void initializeFromInput(RGBImage *image) {
    for (int i = 0; i < image->h * image->r; i++) {
        for (int j = 0; j < image->w * image->r; j++) {
            printf("Enter RGB values for pixel (%d, %d): ", i, j);
            scanf("%hhu %hhu %hhu", &image->px[i][j].red, &image->px[i][j].green, &image->px[i][j].blue);
        }
    }
}

void initializeFromFile(RGBImage *img, const char *filename){
	FILE *f = fopen(filename, "r");
	if(f == NULL){
		fprintf(stderr, "Error load image");
		exit(0);
	}
	fscanf(f, "%d %d %d", img->w, img->h, img->r);
	img->px = (RGBP **)malloc(sizeof(RGBP *) * img->r * img->h);
	for (int i = 0; (i < img->h * img->r); ++i){
		img->px[i] = (RGBP *)malloc(sizeof(RGBP) * img->r * img->w);
	}
	for (int i = 0; i < img->r * img->h; i++) {
        for (int j = 0; j < img->r * img->w; j++) {
            fread(&img->px[i][j], sizeof(RGBP), 1, f);
        }
    }

    fclose(f);
}

void extractComponent(RGBImage *input, RGBImage *output, char component){
	again :
	for (int i = 0; i < input->h * input->r; i++){
		for (int j = 0; j < ; j++){
			RGBP *inputP = &input->p[i][j];
			RGBP *outputP = &output->p[i][j];

			switch(component){
			case 'red':
				outputP->red = inputP->red;
				outputP->green = 0;
				outputP->blue = 0;
				break;
			case 'green':
				outputP->red = 0;
				outputP->green = inputP->green;
				outputP->blue = 0;
				break;
			case 'blue':
				outputP->red = 0;
				outputP->green = 0;
				outputP->blue = inputP->blue;
				break;
			default:
				printf("you must choose red or green or blue");
				printf("choose again? 1/0 : ");
				int choix;
				scanf("%d", choix);
				if(choix) goto again;
				break;
			}
		}
	}
}


RGBImage createImage(int width, int height, int resolution){
	RGBImage img;
	img.w = width;
	img.h = height;
	img.r = resolution;

	img.px = (RGBP **)malloc(height * resolution * sizeof(RGBP *));
	for(int i = 0; i < height * resolution; i++){
		img.px[i] = (RGBP *)malloc(width * resolution * sizeof(RGBP));
	}

	return img;
}