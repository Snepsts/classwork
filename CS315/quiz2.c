/*Write a C language program that will:

1) Define an integer array with size of 100

2) Fill the array with all even numbers from 200 to 400 by using a while loop

3) Print the array with one item per line on the screen

4) Use Linux server to compile and ran your program and copy and paste your
running result to a "Word" document under your program code.
*/

#include <stdio.h>
#define SIZE 100

int main(){
	//1) Define an integer array with size of 100
	int array[SIZE];
	int amount = 200;
	size_t i = 0;

	//2) Fill the array with all even numbers from 200 to 400 by using a while loop
	/* So basically this for loop:
		for(i = 0; i < SIZE; i++, amount += 2)
			array[i] = amount;
	but with a while loop instead. */
	while(i < 100){
		array[i] = amount;
		amount += 2; //note with this logic that it will only go from 200 - 398
	}	             //since our size is limited to 100

	//3) Print the array with one item per line on the screen
	for(size_t i = 0; i < SIZE; i++, amount += 2)
		printf("%d\n", array[i]);

	return 0;
}

/* 4) Use Linux server to compile and ran your program and copy and paste your
   running result to a "Word" document under your program code.
snepsts@michael-laptop:~/classwork/CS315$ cc quiz2.c
snepsts@michael-laptop:~/classwork/CS315$ ./a.out
200
202
204
206
208
210
212
214
216
218
220
222
224
226
228
230
232
234
236
238
240
242
244
246
248
250
252
254
256
258
260
262
264
266
268
270
272
274
276
278
280
282
284
286
288
290
292
294
296
298
300
302
304
306
308
310
312
314
316
318
320
322
324
326
328
330
332
334
336
338
340
342
344
346
348
350
352
354
356
358
360
362
364
366
368
370
372
374
376
378
380
382
384
386
388
390
392
394
396
398
*/
