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

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import javax.script.Compilable;
import javax.script.Invocable;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineFactory;
import javax.script.ScriptEngineManager;

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
public class ScriptManager {
    private static final String PARAMETER_THREADING      = "THREADING";
    private static final String CAPABILITY_MULTITHREADED = "MULTITHREADED";

    private Map<String, Script> scripts;
    private Set<String>         supported;
    private ScriptEngineManager manager;

    public ScriptManager() {
        this.scripts   = new HashMap();
        this.supported = new HashSet();
        this.manager   = new ScriptEngineManager();
        List<ScriptEngineFactory> factories = this.manager.getEngineFactories();
        for(ScriptEngineFactory factory : factories) {
            if(CAPABILITY_MULTITHREADED.equals(
                    factory.getParameter(PARAMETER_THREADING))) {
                ScriptEngine engine = factory.getScriptEngine();
                if((engine instanceof Compilable) && 
                        (engine instanceof Invocable))
                    this.supported.addAll(factory.getNames());
            }
        }
        this.supported = Collections.unmodifiableSet(this.supported);
    }

    public Set<String> getSupportedLanguages() {
        return this.supported;
    }

    public boolean isLanguageSupported(final String language) {
        return this.supported.contains(language);
    }

    public synchronized void add(final Script script) {
        if(script == null)
            throw new IllegalArgumentException(
                    "Argument \"script\" cannot be null.");
        if(!this.isLanguageSupported(script.getLanguage()))
            throw new LanguageNotSupportedException(script.getLanguage());
        String name = script.getName();
        if(this.scripts.containsKey(name))
            throw new ScriptDefinedException(name);
        else {
            this.scripts.put(name, script);
            script.setManager(this);
        }
    }

    public synchronized void remove(final Script script) {
        if(script != null)
            this.remove(script.getName());
    }

    public synchronized void remove(final String name) {
        if(name != null && name.length() > 0)
            this.scripts.remove(name);
    }

    public synchronized Script get(final String name) {
        if(name == null || name.length() == 0)
            throw new IllegalArgumentException(
                    "Argument \"name\" cannot be null or 0 length.");
        return this.scripts.get(name);
    }

    public ScriptEngine getScriptEngine(final String language) {
        if(!this.isLanguageSupported(language))
            throw new LanguageNotSupportedException(language);
        return this.manager.getEngineByName(language);
    }

    public synchronized Collection<Script> getScripts() {
        return Collections.unmodifiableCollection(this.scripts.values());
    }
}
