/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 */

package org.tulipallo.tools.cfd.scripting;

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics</tt>
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 *
 * @author Robert R Murrell
 * @since Java 6
 * @version 1.0 beta
 */
public class Script {
    private String        name;
    private String        description;
    private String        language;
    private String        code;
    private Class         aClass;
    private ScriptManager manager;

    public Script(final String name, final String language) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        if(language == null || language.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"language\" cannot be null or 0 length.");
        this.name = name;
        this.language = language;
    }

    public Script(final String name, final String language, final String code,
                  final Class aClass) {
        this(name, language);
        this.code = code;
        this.implementsInterface(aClass);
    }

    public Script(final String name, final String language, final String code,
                  final String aClass) {
        this(name, language);
        this.code = code;
        try {
            this.implementsInterface(aClass);
        }
        catch(ClassNotFoundException e) {
            throw new IllegalArgumentException(e);
        }
    }

    public ScriptManager getManager() {
        return this.manager;
    }

    void setManager(final ScriptManager manager) {
        if(manager == null)
            throw new IllegalArgumentException(
                    "Argument \"manager\" cannot be null.");
        this.manager = manager;
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public void setDescription(final String description) {
        this.description = description;
    }

    public String getLanguage() {
        return this.language;
    }

    public String getCode() {
        return this.code;
    }

    public void setCode(final String code) {
        this.code = code;
    }

    public Class implementsInterface() {
        return this.aClass;
    }

    public final void implementsInterface(final Class aClass) {
        if(!aClass.isInterface())
            throw new IllegalArgumentException(
                    "Argument \"aClass\" must be an interface.");
        this.aClass = aClass;
    }

    public final void implementsInterface(final String name)
                    throws ClassNotFoundException {
        this.implementsInterface(Class.forName(name));
    }

    public RuntimeScript createRuntimeScript() {
        return new RuntimeScript(this, this.manager.getScriptEngine(
                this.language));
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Script other = (Script) obj;
        if ((this.name == null) ? (other.name != null) :
            !this.name.equals(other.name)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 89 * hash + (this.name != null ? this.name.hashCode() : 0);
        return hash;
    }
}
