import processing.serial.*;

Serial puertoSerie;
int e1 = 0;
int e2 = 0;
boolean l1 = false;
boolean l2 = false;

void setup() {
  size(600, 300);
  
  printArray(Serial.list());
  String puertoName = Serial.list()[0];
  puertoSerie = new Serial(this, puertoName, 9600);
  puertoSerie.bufferUntil('\n');
}

void draw() {
  background(20);
  
  noFill();
  stroke(255);
  strokeWeight(2);
  rect(70, 40, 130, 60, 5);
  fill(255);
  textSize(18);
  textAlign(CENTER, CENTER);
  text("Entradas", 135, 70);
  
  fill(e1 == 1 ? color(0, 255, 0) : color(60));
  stroke(255);
  rect(240, 40, 60, 60);
  fill(255);
  text("E1", 270, 70);
  
  fill(e2 == 1 ? color(0, 255, 0) : color(60));
  stroke(255);
  rect(330, 40, 60, 60);
  fill(255);
  text("E2", 360, 70);
  
  noFill();
  stroke(255);
  rect(70, 160, 130, 60, 5);
  fill(255);
  text("Salidas", 135, 190);
  
  fill(l1 ? color(255, 0, 0) : color(60));
  stroke(255);
  ellipse(270, 190, 60, 60);
  fill(255);
  text("L1", 270, 190);
  
  fill(l2 ? color(255, 0, 0) : color(60));
  stroke(255);
  ellipse(360, 190, 60, 60);
  fill(255);
  text("L2", 360, 190);
}

void mousePressed() {
  if (dist(mouseX, mouseY, 270, 190) < 30) {
    l1 = !l1;
    puertoSerie.write(l1 ? 'A' : 'a');
  }
  
  if (dist(mouseX, mouseY, 360, 190) < 30) {
    l2 = !l2;
    puertoSerie.write(l2 ? 'B' : 'b');
  }
}

void serialEvent(Serial p) {
  String mensaje = p.readString();
  if (mensaje != null) {
    mensaje = trim(mensaje);
    int[] valores = int(split(mensaje, ','));
    if (valores.length >= 4) {
      l1 = (valores[0] == 1);
      l2 = (valores[1] == 1);
      e1 = valores[2];
      e2 = valores[3];
    }
  }
}
