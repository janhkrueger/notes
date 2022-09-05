---
marp: true
theme: base
paginate: true
#header: 'Header content'
footer: 'Jan H. Krüger OIS1 - Basler Versicherungen | What are Feature Toggles'
---

# What are Feature Toggles?

Changes in the way to develop and bring new features live.

![bg right fit](SwitchToogle.jpeg)

---

# Common situation

A new feature needs to be developed but not immeadiatly to be active after a deployment.
* ex a business milestone (Rebranding)
* an external partner is changing apis and the change can happend with short notice.
* branching gets complicated to maintain the more developers are working

---

# Also common

One team finished a feature in software A but the accompaning software B is not ready.

* Different pace in teams. Or simple colleagues are on vacation, having incidents, getting sick.
---
# Other common situation

One does not know how a change will accepted by the customer and one want a test group.

![bg left fit](Automate_Automate_Automate_Looking_right.jpeg)

---

# Consequence: Communication Islands

> "*Branches create distance between developers and we don't want that.*" 
> \- Frank Compagner, Guerilla Games (Horizon Zero, Killzone, Death Stranding)

---

# Difficulties

* Several installations of the same software but with different feature sets.
* Orchestrate application releated deployments and relase dates.

---

![bg opacity:.5](Solution.jpeg)

---
## Feature Toggles


<br/><br/><br/>

aka Feature **Flags**, Freature **Bits**, Feature **Flippers**

![bg opacity:.3](continuous-delivery-feature-flags.jpg)

--- 
# Possible flags

Only examples, limited only by imagination of developers.

* variable in config file
* inMemory variable
* database value
* permission of the user
* data
* costumer value
* 


(PIC of endless solutions)

![bg right fit](IT_Magic.jpeg)

---

# Where are Feature Toggles supported?

Possible in every language allowing alternatitons.

<br/>
Yes, this includes SQL!

---
# variable in config file

---
# inMemory variable

---

# database value

The state of the flag is stored and persitent in the datebase. Therefore one need to trigger an update on the database to change the behaviour of the application.

---

# Permission of the user

An external system manages permissions wich can be used to access to system or features.

There a user can request access to a feature or get it ordered by someone else.

In Baloise context: DIM (Digital Identity Management) with acts as interface for the group active directory.

**Benefit**: The permission and process of grating access is lined up with the group access standard (LAS). Without further doings will compliant for auditors.

---

# data

---
# costumer value
---

# Categories of Toggles

* RELEASE TOGGLES
* EXPERIMENT TOGGLES
* PERMISSION TOGGLES
* OPS TOGGLES
  

  https://martinfowler.com/articles/feature-toggles.html

---
# Code examples

## Short java example

```
   public static void main(String args[]) throws IOException {

      Properties propertyDictionary = readPropertiesFile("flags.properties");
   
      if (   propertyDictionary.getProperty("isPHV").equals("true") ) {
         System.out.println("Hello PHV");
      }
      else {
         System.out.println("Welcome back, KFZ");
      }
   }
```

---

## Other generic short one

```
   if ( getEnvVar("hello") != "" ) {
      std::cout << "Hello World" << std::endl;
   }
   else {
      std::cout << "Hello Mars" << std::endl;
   }
```

---

## random generic example
```
function apiSaveOrder() {
  const useNewAPI = false;
  if (useNewAPI) {
    return apiNewSaveOrder();
  } else {
    return apiOldSaveOrder();
  }
}
```

---

## Example from martinfowler.com

before
```
function reticulateSplines() {
   // current implementation lives here
}
```

---

after
```
function reticulateSplinesOf() {
   var useNewAlgorithm = false:
   // useNewAlgorithm = true; // UNCOMMENT IF YOU ARE WORKING ON THE NEW SR ALGORITHM

   if( useNewAlgorithm ) {
      return enhancedSplineReticulation():
   } else {
      return oldFashionedSplineReticulation();
   }

   function oldFashionedSplineReticulation() {
      // current implementation lives here
   }

   function enhancedSplineReticulation() {
      // TODO: implement better SR algorithm
   }
}
```
