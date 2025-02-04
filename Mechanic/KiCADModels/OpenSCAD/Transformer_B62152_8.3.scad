// Values taken from datasheet
// https://www.mouser.fr/datasheet/2/400/double_aperture_cores-1291315.pdf

FERRITE_H = 8.3;
FERRITE_B = 14.5;
FERRITE_A = 8.5;
FERRITE_C = 5.85;
FERRITE_D = 3.4;


// Increase steps in render to have quality circles
$fs=0.01;

module BasicShape(){
    union(){
        translate([FERRITE_C/2, 0, 0])
            circle($fn = 0, $fa = 12, $fs = 0.01, r = FERRITE_A/2);
        translate([-FERRITE_C/2, 0, 0])
            circle($fn = 0, $fa = 12, $fs = 0.01, r = FERRITE_A/2);

        square([FERRITE_C, FERRITE_A], center=true);
    }
}

module InnerHoles(){

        translate([FERRITE_C/2, 0, 0])
            circle($fn = 0, $fa = 12, $fs = 0.01, r = FERRITE_D/2);

        translate([-FERRITE_C/2, 0, 0])
            circle($fn = 0, $fa = 12, $fs = 0.01, r = FERRITE_D/2);

        
}
module CompleteModel() {
translate([0, 0, FERRITE_H/2])
    rotate([90, 0, 0])
        union(){
            linear_extrude(height = FERRITE_H, convexity = 10, twist = 0)
                difference() {
                    BasicShape();
                    InnerHoles();
                }

            // workaround for error Stepup error "not fused ('union')",
            // also I have to note here that FreeCAD the seccond 
            // bigest abomination in IT (obviously after Yocto)
            translate([0, 0, FERRITE_H/2])
                linear_extrude(height = 1, convexity = 10, twist = 0)
                    BasicShape();
        }

}

CompleteModel();
