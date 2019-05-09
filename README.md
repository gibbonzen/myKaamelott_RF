# myKaamelott_RF

*Objectif: transmettre des commandes par radio*

**Schéma des données**
- ID de l'émetteur
- ID du destinataire
- ID de la commande
- Valeur de la commande

**Type de données**
- ID émetteur
    - 00 = master (émetteur principal)
    - 11 = module sonde météo
    
- ID destinataire, même chiffre que l'émetteur
    - 00 = master
    - 01 = module porte
    - 10 = module mangeoire
    
- ID de la commande 
    /!\ SELON LE MODULE DESTINATAIRE /!\
    1. Module porte
      * 0 : Ouverture
      * 1 : Fermeture
      * 2 : Stop
      * 3 : Modifier l'heure d'ouverture
      * 4 : Modifier l'heure de fermeture
      
    2. Module mangeoire
      * 0 : Nourrir
      * 1 : Modifier la quantité de graines distribuées
      * 2 : Modifier l'heure de nourrissage matinal
      * 3 : Modifier l'heure de nourrissage du soir
      
    3. Master

**Encodage des données**
- ID émetteur : 1 byte (int8_t)
- ID destinateur : 1 byte (int8_t)
- ID commande : 1 byte (int8_t)
- Valeur de la commande 
