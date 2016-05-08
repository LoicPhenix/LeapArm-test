/*Classe LeapArm 
 * Desc : Classe Principale (d�faut)
 * By : Lo�c MONOT
 * Date : 08/05/2016
 * Group : Lo�c MONOT / Pierre-Antoine CHARPENTIER
 * Section : LP SIL IDSE 2016
*/

import java.io.IOException;
import leapMotion.*;
import makeBlock.*;

public class LeapArm {

	public static void main(String[] args) {
        // Keep this process running until Enter is pressed
        System.out.println("Press Enter to quit...");
        
        LeapRun leap = new LeapRun();
        ArmRun bras = new ArmRun();
        
        try {
            System.in.read();
        
        } catch (IOException e) {
            e.printStackTrace();
            leap.finalize();
        }

	}

}
